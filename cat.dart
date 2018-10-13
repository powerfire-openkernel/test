import 'dart:io';

void main(List<String> argv) {
  var file = new File(argv[1]);
  file.readAsString().then((contents) => {
    print(contents);
  });
}
