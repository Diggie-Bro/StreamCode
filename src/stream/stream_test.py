import stream

if __name__ == '__main__':
    strm = stream.Stream("""name::name = run input("What's your name?") >> name->run print("Hello, " + name)""")
    strm.makeStructure()
    print(strm.stream)
