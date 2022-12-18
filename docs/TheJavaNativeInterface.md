# The Java Native Interface (Sheng Liang)

## Table of content

- [Chapter 2: HelloWorld](#chapter02)
- chapter 3
  - [Prompt (JNI String Functions)](#chapter03-prompt)
  - [IntArray (JNI Primitive Array Functions)](#chapter03-intarray)


## <a id="chapter02"> Chapter 2: HelloWorld

- **HelloWorld.java**
```java
class HelloWorld {
    // The "native" modifier indicates that this method is implemented in another language
    private native void print();
    
    public static void main(String[] args) {
        new HelloWorld().print();
    }
    
    // We need to create a native library called HelloWorld.dll on Win32,
    // or libHelloWorld.so on Solaris
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


## <a id="chapter03-prompt"> Chapter 3: Prompt (JNI String Functions)

| JNI Function                                 | Description                                                                                                             |
|----------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
| GetStringChars<br/> ReleaseStringChars       | Obtains or releases a pointer to the contents of a string in Unicode format. May return a copy of the string.           |
| GetStringUTFChars<br/> ReleaseStringUTFChars | Obtains or releases a pointer to the contents of a string in UTF-8 format. May return a copy of the string.             |
| GetStringLength                              | Returns the number of Unicode characters in the string.                                                                 |
| GetStringUTFLength                           | Returns the number of bytes needed (not including the trailing 0) to represent a string in the UTF-8 format.            |
| NewString                                    | Creates a java.lang.String instance that contains the same sequence of characters as the given Unicode C string.        |
| NewStringUTF                                 | Creates a java.lang.String instance that contains the same sequence of characters as the given UTF-8 encoded C string.  |


## <a id="chapter03-intarray"> Chapter 3: IntArray (JNI Primitive Array Functions)

| JNI Function                                           | Description                                                                             |
|--------------------------------------------------------|-----------------------------------------------------------------------------------------|
| Get<Type>ArrayRegion<br/> Set<Type>ArrayRegion         | Copies the contents of primitive arrays to or from a pre-allocated C buffer.            |
| Get<Type>ArrayElements<br/> Release<Type>ArrayElements | Obtains a pointer to the contents of a primitive array. May return a copy of the array. |
| GetArrayLength                                         | Returns the number of elements in the array.                                            |
| New<Type>Array                                         | Creates an array with the given length.                                                 |
