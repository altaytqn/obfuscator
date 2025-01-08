local fh = {}

function fh.read_file(path)
  local file, err = io.open(path, "r")
  if not file then return nil, err end
  local content = file:read("*all")
  file:close()
  return content
end

function fh.write_file(path, content)
  local file, err = io.open(path, "w")
  if not file then return nil, err end
  file:write(content)
  file:close()
  return true
end

function fh.list_dir(path)
  local results = {}
  local popen = io.popen
  local pfile = popen('ls -A "' .. path .. '"')
  for filename in pfile:lines() do
    table.insert(results, filename)
  end
  pfile:close()
  return results
end

return fh
