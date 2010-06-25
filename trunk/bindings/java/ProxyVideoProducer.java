/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class ProxyVideoProducer {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected ProxyVideoProducer(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ProxyVideoProducer obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      tinyWRAPJNI.delete_ProxyVideoProducer(swigCPtr);
    }
    swigCPtr = 0;
  }

  protected void swigDirectorDisconnect() {
    swigCMemOwn = false;
    delete();
  }

  public void swigReleaseOwnership() {
    swigCMemOwn = false;
    tinyWRAPJNI.ProxyVideoProducer_change_ownership(this, swigCPtr, false);
  }

  public void swigTakeOwnership() {
    swigCMemOwn = true;
    tinyWRAPJNI.ProxyVideoProducer_change_ownership(this, swigCPtr, true);
  }

  public ProxyVideoProducer(tmedia_chroma_t chroma) {
    this(tinyWRAPJNI.new_ProxyVideoProducer(chroma.swigValue()), true);
    tinyWRAPJNI.ProxyVideoProducer_director_connect(this, swigCPtr, swigCMemOwn, true);
  }

  public int prepare(int width, int height, int fps) {
    return (getClass() == ProxyVideoProducer.class) ? tinyWRAPJNI.ProxyVideoProducer_prepare(swigCPtr, this, width, height, fps) : tinyWRAPJNI.ProxyVideoProducer_prepareSwigExplicitProxyVideoProducer(swigCPtr, this, width, height, fps);
  }

  public int start() {
    return (getClass() == ProxyVideoProducer.class) ? tinyWRAPJNI.ProxyVideoProducer_start(swigCPtr, this) : tinyWRAPJNI.ProxyVideoProducer_startSwigExplicitProxyVideoProducer(swigCPtr, this);
  }

  public int pause() {
    return (getClass() == ProxyVideoProducer.class) ? tinyWRAPJNI.ProxyVideoProducer_pause(swigCPtr, this) : tinyWRAPJNI.ProxyVideoProducer_pauseSwigExplicitProxyVideoProducer(swigCPtr, this);
  }

  public int stop() {
    return (getClass() == ProxyVideoProducer.class) ? tinyWRAPJNI.ProxyVideoProducer_stop(swigCPtr, this) : tinyWRAPJNI.ProxyVideoProducer_stopSwigExplicitProxyVideoProducer(swigCPtr, this);
  }

  public void setActivate(boolean enabled) {
    tinyWRAPJNI.ProxyVideoProducer_setActivate(swigCPtr, this, enabled);
  }

  public int push(java.nio.ByteBuffer buffer, long size) {
    return tinyWRAPJNI.ProxyVideoProducer_push(swigCPtr, this, buffer, size);
  }

  public static boolean registerPlugin() {
    return tinyWRAPJNI.ProxyVideoProducer_registerPlugin();
  }

}
