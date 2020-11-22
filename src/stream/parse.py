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

    def convertStructToParse(self, structs, meta):
        string = """
startline
IS_VARIABLE_STREAM {isvs}
VARIABLE_STREAM_NAME {vsname}
        """.format(
                isvs=meta['variableStream'],
                vsname=meta['vsName']
        )

        for struct in structs:
            string += """
startstream {order}|{tag}
PARAM {param}
RETURN {return_value}
PERFORM {perform}
endstream
            """.format(
                    order=struct['order'],
                    param=struct['param'],
                    return_value=struct['return_value'],
                    perform=struct['operation'],
                    tag=struct['tag']
            )

        string += "endline"

        return string

    def generateParsedFile(self):
        parsed_string = ""

        with open(self.cdpath, 'r') as f:
            for linecode in f.readlines():
                strm = stream.Stream(linecode.replace("\n", ""))
                strm.makeStructure()

                # parsing
                parsed_string += self.convertStructToParse(strm.stream, strm.metadata)

        with open(self.tgpath, 'w') as f:
            f.write(parsed_string)
