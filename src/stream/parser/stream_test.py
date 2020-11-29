from . import stream

if __name__ == '__main__':
        strm = stream.Stream(
                """IO := I|name::name = run input("What's your name?") >> O|name->run print("Hello, " + name)"""
            )
        strm.makeStructure()
        print(strm.metadata)
        print(strm.stream)

