"""
StreamCode Prototype, under Froglang

stream.py
Stream Structure Object File

Mention @Diggie-Bro/froglang for any help!
"""

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
    
    def makeStructure(self):
        codes = self.code.split(">>")

        # Stream structure
        # { operation, param, return_value, order }

        for index, code in enumerate(codes):
            code.strip()
            self.stream.append({
                "operation": code.split("::")[1] if "::" in code else (code.split("->")[1] if "->" in code else code),
                "param": code.split("->")[0] if "->" in code else None,
                "return_value": (
                        code.split("::")[0].split("->")[1] if "->" in code else code.split("::")[0]
                    ) if "::" in code else None,
                "order": index
            })

