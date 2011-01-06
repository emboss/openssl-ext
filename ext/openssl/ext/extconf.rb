=begin
= $RCSfile$ -- Generator for Makefile

= Info
  'OpenSSL Extensions for Ruby'
  Copyright (C) 2011  Martin Boßlet <Martin.Bosslet@googlemail.com>
  All rights reserved.

= Licence
  This program is licenced under the same licence as Ruby.
  (See the file 'LICENCE'.)

=end

require "mkmf"

dir_config("openssl")

message "=== OpenSSL Extensions for Ruby configurator ===\n"

message "=== Checking for system dependent stuff... ===\n"
have_header("assert.h")

result = pkg_config("openssl") && have_header("openssl/ssl.h")

unless result
  message "=== Checking for required stuff failed. ===\n"
  message "OpenSSL library not found on this system.\n"
  exit 1
end

%w"rb_str_set_len rb_block_call".each {|func| have_func(func, "ruby.h")}

message "=== Checking for OpenSSL features... ===\n"

unless have_header("openssl/ts.h")
  message "OpenSSL 1.0.0 or later required.\n"
  exit 1
end

message "=== Checking done. ===\n"

create_header
create_makefile("openssl/ext")
message "Done.\n"
