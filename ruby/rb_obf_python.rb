require_relative 'rb_utils'

def obf_python(code)
  lines = code.split("\n")
  scrambled = lines.map do |l|
    tokens = tokenize_line(l)
    tokens.map { |t| shuffle_string(t) }.join("-RND-")
  end
  combined = scrambled.map { |s| base64_encode(s) }.join("\n")
  wrapped = combined.lines.map { |cl| "#PY:#{cl.chomp}" }.join("\n")
  wrapped
end
