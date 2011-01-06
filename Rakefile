require 'rubygems'
require 'rake'
require 'rake/clean'
require 'rake/gempackagetask'
require 'rake/rdoctask'
require 'rake/testtask'

spec = Gem::Specification.new do |s|
  s.name = 'openssl-ext'
  s.version = '0.0.1'
  s.has_rdoc = true
  s.extra_rdoc_files = ['README', 'LICENSE']
  s.summary = 'Provides additional features for the OpenSSL standard library.'
  s.description = <<-EOF 
    OpenSSL extensions provides additional features that currently do not exist
    in this form in the OpenSSL standard library. E.g., OpenSSL extensions 
    provides support for RFC 3161 timestamps. 
  EOF
  s.author = 'Martin Bosslet'
  s.email = 'Martin.Bosslet@googlemail.com'
  s.homepage = 'https://github.com/emboss'
  s.extensions << 'ext/openssl/ext/extconf.rb'
  s.files = %w(LICENSE README Rakefile) + Dir.glob("{bin,ext,lib,spec,test}/**/*")
	s.test_files = FileList['test/**/test_*.rb']
  s.require_path = "lib"
  s.bindir = "bin"
end

Rake::GemPackageTask.new(spec) do |p|
  p.gem_spec = spec
  p.need_tar = true
  p.need_zip = true
end

Rake::RDocTask.new do |rdoc|
  files =['README', 'LICENSE', 'lib/**/*.rb', 'ext/**/*.c']
  rdoc.rdoc_files.add(files)
  rdoc.main = "README" # page to start on
  rdoc.title = "openssl-ext Docs"
  rdoc.rdoc_dir = 'doc/rdoc' # rdoc output folder
end

Rake::TestTask.new do |t|
  t.test_files = FileList['test/**/*.rb']
end
