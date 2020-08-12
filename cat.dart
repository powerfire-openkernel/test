import 'dart:io';

void main(List<String> argv) {
  new File(argv[1]).readAsString().then(print);
}
