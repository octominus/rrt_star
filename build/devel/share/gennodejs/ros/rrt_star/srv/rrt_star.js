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
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rrt_star/rrt_starRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd932f4cd1a6dbfdd4cd7d1cc6f4496d5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 X1
    float32 Y1
    float32 X2
    float32 Y2
    
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

    return resolved;
    }
};

class rrt_starResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type rrt_starResponse
    // Serialize message field [result]
    bufferOffset = _serializer.bool(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type rrt_starResponse
    let len;
    let data = new rrt_starResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rrt_star/rrt_starResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eb13ac1f1354ccecb7941ee8fa2192e8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool result
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new rrt_starResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = false
    }

    return resolved;
    }
};

module.exports = {
  Request: rrt_starRequest,
  Response: rrt_starResponse,
  md5sum() { return '727ba677c1ac4e2fb5cb99c510508116'; },
  datatype() { return 'rrt_star/rrt_star'; }
};
