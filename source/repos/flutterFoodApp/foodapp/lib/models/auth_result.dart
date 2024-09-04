class AuthResult {
  String token;
  bool result;
  List<String> errors;

  AuthResult(
      {required this.token, required this.result, this.errors = const []});

  factory AuthResult.fromJson(Map<String, dynamic> json) => AuthResult(
        token: json['Token'] ?? '',
        result: json['Result'],
        errors: List<String>.from(json['Errors'] ?? []),
      );
}
