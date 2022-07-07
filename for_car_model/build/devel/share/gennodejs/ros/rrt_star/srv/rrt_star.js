// Auto-generated. Do not edit!

// (in-package rrt_star.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class rrt_starRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.X1 = null;
      this.Y1 = null;
      this.X2 = null;
      this.Y2 = null;
      this.time = null;
      this.time_type = null;
    }
    else {
      if (initObj.hasOwnProperty('X1')) {
        this.X1 = initObj.X1
      }
      else {
        this.X1 = 0.0;
      }
      if (initObj.hasOwnProperty('Y1')) {
        this.Y1 = initObj.Y1
      }
      else {
        this.Y1 = 0.0;
      }
      if (initObj.hasOwnProperty('X2')) {
        this.X2 = initObj.X2
      }
      else {
        this.X2 = 0.0;
      }
      if (initObj.hasOwnProperty('Y2')) {
        this.Y2 = initObj.Y2
      }
      else {
        this.Y2 = 0.0;
      }
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('time_type')) {
        this.time_type = initObj.time_type
      }
      else {
        this.time_type = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type rrt_starRequest
    // Serialize message field [X1]
    bufferOffset = _serializer.float32(obj.X1, buffer, bufferOffset);
    // Serialize message field [Y1]
    bufferOffset = _serializer.float32(obj.Y1, buffer, bufferOffset);
    // Serialize message field [X2]
    bufferOffset = _serializer.float32(obj.X2, buffer, bufferOffset);
    // Serialize message field [Y2]
    bufferOffset = _serializer.float32(obj.Y2, buffer, bufferOffset);
    // Serialize message field [time]
    bufferOffset = _serializer.float32(obj.time, buffer, bufferOffset);
    // Serialize message field [time_type]
    bufferOffset = _serializer.string(obj.time_type, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type rrt_starRequest
    let len;
    let data = new rrt_starRequest(null);
    // Deserialize message field [X1]
    data.X1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Y1]
    data.Y1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [X2]
    data.X2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Y2]
    data.Y2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [time]
    data.time = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [time_type]
    data.time_type = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.time_type.length;
    return length + 24;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rrt_star/rrt_starRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '99afacc64c7bfd433dc86f45cfb7a825';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 X1
    float32 Y1
    float32 X2
    float32 Y2
    float32 time
    string time_type
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new rrt_starRequest(null);
    if (msg.X1 !== undefined) {
      resolved.X1 = msg.X1;
    }
    else {
      resolved.X1 = 0.0
    }

    if (msg.Y1 !== undefined) {
      resolved.Y1 = msg.Y1;
    }
    else {
      resolved.Y1 = 0.0
    }

    if (msg.X2 !== undefined) {
      resolved.X2 = msg.X2;
    }
    else {
      resolved.X2 = 0.0
    }

    if (msg.Y2 !== undefined) {
      resolved.Y2 = msg.Y2;
    }
    else {
      resolved.Y2 = 0.0
    }

    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.time_type !== undefined) {
      resolved.time_type = msg.time_type;
    }
    else {
      resolved.time_type = ''
    }

    return resolved;
    }
};

class rrt_starResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.path_result = null;
      this.time_result = null;
    }
    else {
      if (initObj.hasOwnProperty('path_result')) {
        this.path_result = initObj.path_result
      }
      else {
        this.path_result = false;
      }
      if (initObj.hasOwnProperty('time_result')) {
        this.time_result = initObj.time_result
      }
      else {
        this.time_result = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type rrt_starResponse
    // Serialize message field [path_result]
    bufferOffset = _serializer.bool(obj.path_result, buffer, bufferOffset);
    // Serialize message field [time_result]
    bufferOffset = _serializer.float32(obj.time_result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type rrt_starResponse
    let len;
    let data = new rrt_starResponse(null);
    // Deserialize message field [path_result]
    data.path_result = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [time_result]
    data.time_result = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rrt_star/rrt_starResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '74207e5810b32b18ad0309953955f675';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool path_result
    float32 time_result
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new rrt_starResponse(null);
    if (msg.path_result !== undefined) {
      resolved.path_result = msg.path_result;
    }
    else {
      resolved.path_result = false
    }

    if (msg.time_result !== undefined) {
      resolved.time_result = msg.time_result;
    }
    else {
      resolved.time_result = 0.0
    }

    return resolved;
    }
};

module.exports = {
  Request: rrt_starRequest,
  Response: rrt_starResponse,
  md5sum() { return '4fa07ef2fe36c88d0f047badd795303f'; },
  datatype() { return 'rrt_star/rrt_star'; }
};
