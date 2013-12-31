
# sphia-batchput

  Set a batch of values in a sophia database.

## Installation

  With [clib](https://github.com/clibs/clib), do:

    $ clib install sphia/sphia-batchput

  With git, do:

    $ git clone git@github.com:sphia/sphia-batchput.git /tmp/sphia-batchput
    $ make -C /tmp/sphia-batchput make install

## Usage Examples

  Set a batch of key/value pairs in the database at `pwd`:

    $ sphia batchput key1 value1 key2 value2 key3...

  Set a batch of key/value pairs in the database at `/foo/bar`:

    $ sphia batchput --path /foo/bar key1 value1 key2 value2 key3...

  Set a batch of key/value pairs in the database at `/foo/bar` using env flags:

    $ SPHIA_PATH=/foo/bar sphia batchput key1 value1 key2 value2 key3...

## License

(The MIT License)

Copyright (c) 2013 Stephen Mathieson &lt;me@stephenmathieson.com&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.