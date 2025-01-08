require_relative 'rb_utils'

def obf_csharp(code)
  segments = code.split("\n")
  result = segments.map do |seg|
    r = seg.chars.shuffle.join
    hashed = insert_hashes(r)
    "/*CS@#{base64_encode(hashed)}*/"
  end
  result.join("\n")
end
