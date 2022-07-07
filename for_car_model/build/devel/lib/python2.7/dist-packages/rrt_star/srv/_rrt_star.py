# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rrt_star/rrt_starRequest.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class rrt_starRequest(genpy.Message):
  _md5sum = "99afacc64c7bfd433dc86f45cfb7a825"
  _type = "rrt_star/rrt_starRequest"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float32 X1
float32 Y1
float32 X2
float32 Y2
float32 time
string time_type
"""
  __slots__ = ['X1','Y1','X2','Y2','time','time_type']
  _slot_types = ['float32','float32','float32','float32','float32','string']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       X1,Y1,X2,Y2,time,time_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(rrt_starRequest, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.X1 is None:
        self.X1 = 0.
      if self.Y1 is None:
        self.Y1 = 0.
      if self.X2 is None:
        self.X2 = 0.
      if self.Y2 is None:
        self.Y2 = 0.
      if self.time is None:
        self.time = 0.
      if self.time_type is None:
        self.time_type = ''
    else:
      self.X1 = 0.
      self.Y1 = 0.
      self.X2 = 0.
      self.Y2 = 0.
      self.time = 0.
      self.time_type = ''

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_5f().pack(_x.X1, _x.Y1, _x.X2, _x.Y2, _x.time))
      _x = self.time_type
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 20
      (_x.X1, _x.Y1, _x.X2, _x.Y2, _x.time,) = _get_struct_5f().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.time_type = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.time_type = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_5f().pack(_x.X1, _x.Y1, _x.X2, _x.Y2, _x.time))
      _x = self.time_type
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 20
      (_x.X1, _x.Y1, _x.X2, _x.Y2, _x.time,) = _get_struct_5f().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.time_type = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.time_type = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_5f = None
def _get_struct_5f():
    global _struct_5f
    if _struct_5f is None:
        _struct_5f = struct.Struct("<5f")
    return _struct_5f
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rrt_star/rrt_starResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class rrt_starResponse(genpy.Message):
  _md5sum = "74207e5810b32b18ad0309953955f675"
  _type = "rrt_star/rrt_starResponse"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """bool path_result
float32 time_result
"""
  __slots__ = ['path_result','time_result']
  _slot_types = ['bool','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       path_result,time_result

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(rrt_starResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.path_result is None:
        self.path_result = False
      if self.time_result is None:
        self.time_result = 0.
    else:
      self.path_result = False
      self.time_result = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_Bf().pack(_x.path_result, _x.time_result))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 5
      (_x.path_result, _x.time_result,) = _get_struct_Bf().unpack(str[start:end])
      self.path_result = bool(self.path_result)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_Bf().pack(_x.path_result, _x.time_result))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 5
      (_x.path_result, _x.time_result,) = _get_struct_Bf().unpack(str[start:end])
      self.path_result = bool(self.path_result)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_Bf = None
def _get_struct_Bf():
    global _struct_Bf
    if _struct_Bf is None:
        _struct_Bf = struct.Struct("<Bf")
    return _struct_Bf
class rrt_star(object):
  _type          = 'rrt_star/rrt_star'
  _md5sum = '4fa07ef2fe36c88d0f047badd795303f'
  _request_class  = rrt_starRequest
  _response_class = rrt_starResponse
