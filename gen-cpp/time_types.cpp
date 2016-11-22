/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "time_types.h"

#include <algorithm>



const char* valuesStruct::ascii_fingerprint = "9118FDD77343DD231D97C424A53D2DCF";
const uint8_t valuesStruct::binary_fingerprint[16] = {0x91,0x18,0xFD,0xD7,0x73,0x43,0xDD,0x23,0x1D,0x97,0xC4,0x24,0xA5,0x3D,0x2D,0xCF};

uint32_t valuesStruct::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->unixtime);
          this->__isset.unixtime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->t0);
          this->__isset.t0 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->t1);
          this->__isset.t1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->t2);
          this->__isset.t2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->t3);
          this->__isset.t3 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t valuesStruct::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("valuesStruct");

  xfer += oprot->writeFieldBegin("unixtime", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->unixtime);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("t0", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->t0);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("t1", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->t1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("t2", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->t2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("t3", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->t3);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(valuesStruct &a, valuesStruct &b) {
  using ::std::swap;
  swap(a.unixtime, b.unixtime);
  swap(a.t0, b.t0);
  swap(a.t1, b.t1);
  swap(a.t2, b.t2);
  swap(a.t3, b.t3);
  swap(a.__isset, b.__isset);
}


