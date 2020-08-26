# ARCANE
ARCANE Runs, Compiles, And Never Explodes

A programming language and bytecode VM. (ARCVM)

WIP

Tested on Windows 10 and multiple Linux distros with gcc and clang

# Sample Code

```zig
fn main(): int{
    i := 0;
    x : int = 5;
    result := add(i, x);
    ret result;
}
fn add(a : int, b : int): int {
    ret a + b;
}
```
Syntax highlighting is a bit off. Use this extension for correct highlighting in VSCode.
Syntax Highlighting : https://github.com/BrandonKi/arcane-syntax-highlighter


# Notes

replace reintrpret cast with safe version

move everything to arena allocator

make assignment an expression

https://trello.com/b/tZJWGk7b/arcane

Minimal type checking is done at runtime.
Otherwise all type checking should/will be done at compile time.
Only checks for fatal errors at runtime.


Bytecode files store variables in Little Endian 




### RESOURCES FOR LATER

- https://www.scadacore.com/tools/programming-calculators/online-hex-converter/
- https://en.wikipedia.org/wiki/Java_class_file
- https://web.stanford.edu/class/archive/cs/cs143/cs143.1128/lectures
- https://web.stanford.edu/class/archive/cs/cs143/cs143.1128/lectures/13/Slides13.pdf

