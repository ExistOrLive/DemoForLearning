void main() {
  //Uri uri = Uri.https("gitee.com", "/api/v5/search/repositories", {"q": "?/"});
  Uri? uri = null;
  try {
    uri = Uri.tryParse("");
  } on FormatException {
    uri = null;
  } finally {
    print(uri);
  }

  print(uri.runtimeType);
}
