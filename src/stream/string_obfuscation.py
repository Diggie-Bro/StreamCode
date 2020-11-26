"""
StreamCode Prototype, under Froglang

string_obfuscation.py
Stream String Obfuscation file.

Notice! This is not for security.

Mention @Diggie-Bro/froglang for any help!
"""

import keywords

def encode(s):
    return keywords.dummy_keyword["OBFUSSTRING"].join([str(ord(c)) for c in list(s)])

def decode(s: str):
    for splited in s.split(keywords.dummy_keyword["OBFUSSTRING"]):
        s = s.replace(splited, chr(int(splited)))

    return s.replace(keywords.dummy_keyword["OBFUSSTRING"], '')
     
