"""
StreamCode Prototype, under Froglang

parse.py
Stream parsed file generator. 

Mention @Diggie-Bro/froglang for any help!
"""
import stream

class Generator:
    def __init__(self, codepath, targetpath):
        self.tgpath = targetpath
        self.cdpath = codepath

    def convertStructToParse(self, structs):
        string = ""

        for struct in structs:
            string += """
            startstream {order}
            PARAM {param}
            RETURN {return_value}
            PERFORM {perform}
            endstream
            """.format(
                    order=struct['order'],
                    param=struct['param'],
                    return_value=struct['return_value'],
                    perform=struct['operation']
            )
            
        return string

    def generateParsedFile(self):
        parsed_string = ""

        with open(self.cdpath, 'r') as f:
            strm = stream.Stream(f.read())
            strm.makeStructure()

            # parsing
            parsed_string = self.convertStructToParse(strm.stream)

        with open(self.tgpath, 'w') as f:
            f.write(parsed_string)
