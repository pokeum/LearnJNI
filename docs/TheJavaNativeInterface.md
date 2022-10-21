# The Java Native Interface (Sheng Liang)

## Table of content

- [Chapter 2: HelloWorld](#chapter02)


## <a id="chapter02"> Chapter 2: HelloWorld

- **HelloWorld.java**
```java
class HelloWorld {
    private native void print();
    public static void main(String[] args) {
        new HelloWorld().print();
    }
    static {
        System.loadLibrary("HelloWorld");
    }
}
```

```zsh
# Generate HelloWorld.h
javah -jni HelloWorld
javac HelloWorld.java -h .

# Generate HelloWorld.class 
$ javac HelloWorld.java
```

- **소스코드 컴파일**
```zsh
gcc -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin/" -o libHelloWorld.jnilib -shared HelloWorld.c
```

```zsh
# Generate HelloWorld.class
javac HelloWorld.java

# Run HelloWorld
java HelloWorld
```