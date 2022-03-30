#include "HelloJava.h"
#include <iostream>

using namespace std;

JNIEXPORT jdouble JNICALL Java_HelloJava_calculateSTDDev(JNIEnv* env, jobject thisObj, jintArray inJNIArray) {
    jdouble mean = Java_HelloJava_calculateMean(env, thisObj, inJNIArray);
    jint* array = env->GetIntArrayElements(inJNIArray, NULL);
    if (NULL == array) return 0;
    jsize length = env->GetArrayLength(inJNIArray);
    jdouble var = 0.0;
#pragma omp parallel for reduction(+: var)
    for (int i = 0; i < length; ++i) {
        var += pow((double)array[i] - mean, 2);
    }
    jdouble std = sqrt(var / length);
#pragma omp barrier
    env->ReleaseIntArrayElements(inJNIArray, array, 0);
    
    return std;
}

JNIEXPORT jdouble JNICALL Java_HelloJava_calculateMean(JNIEnv* env, jobject thisObj, jintArray inJNIArray) {
    jint* array = env->GetIntArrayElements(inJNIArray, NULL);
    if (NULL == array) return 0;
    jsize length = env->GetArrayLength(inJNIArray);
    jint sum = 0;
#pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    jdouble average = (jdouble)sum / length;
#pragma omp barrier
    env->ReleaseIntArrayElements(inJNIArray, array, 0);

    return average;
}
