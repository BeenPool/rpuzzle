rpuzzle
=======

alibpuzzle wrapper.

how to use
----------

> require 'rpuzzle'
> 
> puzzle = RPuzzle.new
> 
> begin
>     p puzzle.diff(file1,file2)
> rescue
>     puts $!
> end
> 
