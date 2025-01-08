require_relative 'rb_utils'

def obf_cpp(code)
  lines = code.split("\n")
  modded = lines.map do |l|
    rev = l.reverse
    inject_rand_symbols(rev)
  end
  final = modded.map do |m|
    encoded = base64_encode(m)
    "//CPP:#{encoded}"
  end
  final.join("\n")
end
