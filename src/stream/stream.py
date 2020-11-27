"""
StreamCode Prototype, under Froglang

stream.py
Stream Structure Object File

Mention @Diggie-Bro/froglang for any help!
"""
import re
import string_obfuscation as strobfus

"""
Stream Class
Stream Structure Object
----
Generate, and return Stream structure.

:param code: str
"""
class Stream:
    def __init__(self, code: str):
        self.code = code
        self.stream = []
        self.metadata = {}
    
    def makeStructure(self):
        self.metadata = {
            "variableStream": True if ":=" in self.code else False,
            "vsName": self.code.split(":=")[0].strip() if ":=" in self.code else None
        }
        codes = self.code.split(">>")

        # Stream structure
        # { variableStream, vsName, operation, param, return_value, order, tag }

        for index, code in enumerate(codes):
            code.strip()
            
            # string obfuscation not to confuse during parsing.
            # string only support ", not '
            stringRangeIndex: int = None
            
            for i, char in enumerate(code):
                if char == '"':
                    if stringRangeIndex != None:
                        stringPart = code[stringRangeIndex + 1: i]
                        code = code.replace(stringPart, strobfus.encode(stringPart))
                        stringRangeIndex = None
                    else:
                        stringRangeIndex = i
            
            self.stream.append({
                "operation": code.split("::")[1].strip() if "::" in code else (code.split("->")[1].strip() if "->" in
                    code else code.strip()),
                "param": (
                        code.split("|")[1].split("->")[0].strip() if "|" in code else (
                            code.split(":=")[1].split("->")[0].strip() if ":=" in code else code.split("->")[0].strip()
                        )
                    ) if "->" in code else None,
                "return_value": (
                        code.split("::")[0].split("->")[1].strip() if "->" in code else (
                            code.split("::")[0].split("|")[1].strip() if "|" in code else (
                                code.split("::")[0].split(":=")[1].strip() if ":=" in code else
                                code.split("::")[0].strip()
                            )
                        )
                    ) if "::" in code else None,
                "order": index,
                "tag": (
                        code.split(":=")[1].split("|")[0].strip() if ":=" in code else code.split("|")[0].strip()
                    ) if "|" in code else None
            })

