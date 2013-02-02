Gem::Specification.new do |s|
  s.name        = 'rpuzzle'
  s.version     = '0.0.2'
  s.date        = '2013-01-28'
  s.summary     = "libpuzzle"
  s.description = "libpuzzle wrapper"
  s.authors     = ["BeenPool"]
  s.email       = 'beenpool@gmail.com'
  s.files       = ['lib/rpuzzle.rb',
                   'ext/rpuzzle/rpuzzle.c']
  s.extensions  << 'ext/rpuzzle/extconf.rb'
  s.homepage    = 'http://rubygems.org/gems/libpuzzle'
end
