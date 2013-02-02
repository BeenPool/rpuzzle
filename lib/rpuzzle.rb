require_relative '../ext/rpuzzle/rpuzzle'

class RPuzzle
  def diff(file1, file2)
    raise "#{file1} Not Found." unless  File.exist?(file1) 
    raise "#{file2} Not Found." unless  File.exist?(file2) 
    vector_normalized_distance(file1, file2)
  end 
end
