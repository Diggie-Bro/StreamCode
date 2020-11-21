import parse

if __name__ == '__main__':
    parser = parse.Generator(codepath="proto/basic.streamcode", targetpath="proto/basic_parsed.streamparse")
    parser.generateParsedFile()
