import sys
import StringIO

# template for output file
template = """\
// { dg-do link }
// Generated by overload.py

struct S{};

S l;                             // lvalue (l)
S const cl = l;                  // const lvalue (cl)
S r() { return l; }              // rvalue (r)
S const cr() { return l; }       // const rvalue (cr)
S & nl = l;                      // named lvalue reference (nl)
S const & ncl = l;               // named const lvalue reference (ncl)
S && nr = l;                     // named rvalue reference (nr)
S const && ncr = l;              // named const rvalue reference (ncr)
S & ul() { return l; }           // unnamed lvalue reference (ul)
S const & ucl() { return l; }    // unnamed const lvalue reference (ucl)
S && ur() { return l; }          // unnamed rvalue reference (ur)
S const && ucr() { return l; }   // unnamed const rvalue reference (ucr)

%(funcs)s
int main()
{
%(calls)s
  return 0;
}
"""

# parameters to overload on
params = ('S&', 'const S&', 'S&&', 'const S&&')

# arguments to test overloads on in (function prefix, argument) tuples
args = (
  ('l', 'l'),
  ('cl', 'cl'),
  ('r', 'r()'),
  ('cr', 'cr()'),
  ('nl', 'nl'),
  ('ncl', 'ncl'),
  ('nr', 'nr'),
  ('ncr', 'ncr'),
  ('ul', 'ul()'),
  ('ucl', 'ucl()'),
  ('ur', 'ur()'),
  ('ucr', 'ucr()'),
)

# everybody get out your sharpened number 2 pencils
answers = {
  'l':  ( 3, #0001
          2, #0010
          2, #0011
          1, #0100
          1, #0101
          1, #0110
          1, #0111
          0, #1000
          0, #1001
          0, #1010
          0, #1011
          0, #1100
          0, #1101
          0, #1110
          0, #1111
        ),
  'cl': ( 3, #0001
          None, #0010
          3, #0011
          1, #0100
          1, #0101
          1, #0110
          1, #0111
          None, #1000
          3, #1001
          None, #1010
          3, #1011
          1, #1100
          1, #1101
          1, #1110
          1, #1111
        ),
   'r': (3, #0001
          2, #0010
          2, #0011
          1, #0100
          3, #0101
          2, #0110
          2, #0111
          None, #1000
          3, #1001
          2, #1010
          2, #1011
          1, #1100
          3, #1101
          2, #1110
          2, #1111
        ),
  'cr': ( 3, #0001
          None, #0010
          3, #0011
          1, #0100
          3, #0101
          1, #0110
          3, #0111
          None, #1000
          3, #1001
          None, #1010
          3, #1011
          1, #1100
          3, #1101
          1, #1110
          3, #1111
        )}
answers['nl'] = answers['l']
answers['ncl'] = answers['cl']
answers['nr'] = answers['l']
answers['ncr'] = answers['cl']
answers['ul'] = answers['l']
answers['ucl'] = answers['cl']
answers['ur'] = answers['r']
answers['ucr'] = answers['cr']

funcs = StringIO.StringIO()
calls = StringIO.StringIO()

for func_prefix, arg in args:
  for param_set in range(1, 1<<len(params)):
    answer = answers[func_prefix][param_set-1]
    if answer is None:
      continue

    func_name = []
    func_params = []
    for param_idx in range(len(params)):
      if param_set & (1 << (len(params)-param_idx-1)):
        func_params.append(param_idx)
        func_name.append('1')
      else:
        func_name.append('0')

    func_name = func_prefix + ''.join(func_name)

    for param_idx in func_params:
      body = param_idx == answer and ' {}' or ';'
      funcs.write('void %s(%s)%s\n' % (func_name, params[param_idx], body))
    funcs.write('\n')

    calls.write('  %s(%s);\n' % (func_name, arg))

sys.stdout.write(template % { 'funcs': funcs.getvalue(),
                              'calls': calls.getvalue()})

