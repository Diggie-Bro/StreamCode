# The StreamCode Programming Language 

<a><img src="https://img.shields.io/badge/process-Prototyping-red"></a>
<a href="https://github.com/Diggie-Bro/Frog-Prototype-StreamCode/actions/"><img src="https://img.shields.io/badge/build-pass-green"></a>
<a href="https://www.python.org"><img src="https://img.shields.io/badge/language->=python3.5-blue"></a>
<a href="./LICENSE"><img src="https://img.shields.io/badge/LICENSE-MIT-pink"></a>

![icon](./frogstream.png)  
StreamCode is open-source programming language that it is **Stream-friendly** and simple to use.

## About StreamCode
### Basic Stream From
### `A >> B >> C`
This is our basic form of StreamCode. `A` is input process of stream. `B` is filter, and `C` is output process.   
Stream should include at lease two process. The stream will be run following LTR(Left To Right) rule.

---

### `[return]::A >> [param]->B`
`A` should return value to pipeline, so you can return value in [return] as writing variable name.   
Also, `B` should load data from pipeline, so you can make parameter in [param] as writing variable name.
**Remember, form of `[return]` should correspond with `[param]`**

> #### example
```
name::name = run input("What's your name?") >> name->run print("Hello, " + name)
```
> you can also use this form like this:
> `[return]::A >> [param]->[return]::B` => this stream return [return].

---

### `A >> B >> [tag]|C`
In this stream, process `C`'s name is [tag]. So, if you want to use process C again, you can just write like this.  

`A >> B >> [tag]|C >> [tag]`  

It'll work well, but **Remember, this tag doesn't have C's param and return.** You should write `[param] and [return]`. 
It is very important to StreamCode, because this formation'll be used in **IF and LOOP**

> #### tip
> General Form of Process: `[tag]|[param]->[return]::[operation]`  
> General Form of Stream: `[tag]|[return]::A >> [tag]|[param]->[return]::B >> [tag]|[param]->[return]::C`

### (advanced) `[streamname] := [param]->[return]::A >> [param]->[return]::B >> [param]->[return]::C`
You can save stream to variable stream. Also you can load that stream in another stream like `A >> [streamname] >> B`. 
When you save stream to variable, the first process should have `[param]->[return]`, like **function**.

> #### example
> This is wrong, guess why :D
```
hello_name := name->filtered_name::filtered_name = "Hello, " + name >> filtered_name->run print(filtered_name)
username::username = run input("What's your name?") >> hello_name
```
> The answer is "hello_name's parameter doesn't correspond with stream's return variable name"  
> **Replace 'hello_name' as hello_name's stream.**
```
username::username = run input("What's your name?") >> name->filtered_name::filtered_name = "Hello, " + name >> filtered_name->run print(filtered_name)
```
> As you can see, this stream has grammar error. So, you should keep in mind that you should check `variable stream`'s
> parameter correspond with `main stream`'s return value.
