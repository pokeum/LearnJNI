//
// Created by Po Keum Cho on 2022/10/21.
//
#include "Prompt.h"
#include <stdio.h>

JNIEXPORT jstring JNICALL
Java_Prompt_getLine(JNIEnv *env, jobject obj, jstring prompt)
{
    char buf[128];

    // Unicode format → UTF-8 format
    const char *str = (*env)->GetStringUTFChars(env, prompt, NULL);

    if (str == NULL) {
        return NULL;    /* OutOfMemory already thrown */
    }
    printf("%s", str);
    (*env)->ReleaseStringUTFChars(env, prompt, str);
    /* We assume here that the user does not type more than 127 characters */
    scanf("%s", buf);

    // Creates a java.lang.String instance that contains the same sequence of characters as given
    // UTF-8 encoded C string.
    return (*env)->NewStringUTF(env, buf);
}