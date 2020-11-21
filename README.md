# 🛠 The Frog Programming Languag Prototype

Prototype StreamCode
---

<img src="https://img.shields.io/badge/process-Prototyping-red">
<a href="https://github.com/Diggie-Bro/Frog-Prototype-StreamCode/actions/"><img src="https://img.shields.io/badge/build-pass-green"></a>
<a href="https://www.python.org"><img src="https://img.shields.io/badge/language->=python3.5-blue"></a>
<a href="./LICENSE"><img src="https://img.shields.io/badge/LICENSE-MIT-pink"></a>
<a href="https://github.com/Diggie-Bro"><img src="https://img.shields.io/badge/DiggieBro-white"></a>
<div align="center">
    <img src="https://raw.githubusercontent.com/Diggie-Bro/Frog-prototype-CommandCode/master/img/FrogSungyi.png"/>  
    <p>StreamCode is basic grammar of Froglang. It was inspired by <strong>C++</strong>'s stream, and <a href="https://github.com/matz/streem">matz's Streem PL</a></p>
    <blockquote><p><strong>This prototype is under of Froglang, so it'll follow Froglang
    Grammar.</strong></p></blockquote>
</div>

About StreamCode
---

### `A >> B >> C`
This is our basic form of StreamCode. `A` is input process of stream. `B` is filter, and `C` is output process.   
Stream should include at lease two process. The stream will be run following LTR(Left To Right) rule.

### `[return]::A >> [param]:B`
`A` should return value to pipeline, so you can return value in [return] as writing variable name.   
Also, `B` should load data from pipeline, so you can make parameter in [param] as writing variable name.
*Rember, form of `[return]` should correspond with `[param]`*

> #### example
> ```
> name::name = run input("What's your name?") >> name:run print("Hello, " + name)
> ```

#### We're developing more grammar. Stay tuned ;)
