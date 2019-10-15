/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class MESSAGE_INFO {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected MESSAGE_INFO(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(MESSAGE_INFO obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        shctiJNI.delete_MESSAGE_INFO(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setWEventCode(int value) {
    shctiJNI.MESSAGE_INFO_wEventCode_set(swigCPtr, this, value);
  }

  public int getWEventCode() {
    return shctiJNI.MESSAGE_INFO_wEventCode_get(swigCPtr, this);
  }

  public void setNReference(int value) {
    shctiJNI.MESSAGE_INFO_nReference_set(swigCPtr, this, value);
  }

  public int getNReference() {
    return shctiJNI.MESSAGE_INFO_nReference_get(swigCPtr, this);
  }

  public void setDwParam(long value) {
    shctiJNI.MESSAGE_INFO_dwParam_set(swigCPtr, this, value);
  }

  public long getDwParam() {
    return shctiJNI.MESSAGE_INFO_dwParam_get(swigCPtr, this);
  }

  public MESSAGE_INFO() {
    this(shctiJNI.new_MESSAGE_INFO(), true);
  }

}
