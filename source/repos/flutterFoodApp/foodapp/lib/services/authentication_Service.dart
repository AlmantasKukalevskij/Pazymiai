import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:flutter_secure_storage/flutter_secure_storage.dart';

class AuthenticationService {
  static const storage = FlutterSecureStorage();
  static const String baseUrl =
      'https://localhost:7299/api/Authentication'; // Adjust to your actual URL

  static Future<bool> login(String email, String password) async {
    try {
      final url = Uri.parse('$baseUrl/Login');
      final response = await http.post(
        url,
        headers: {'Content-Type': 'application/json'},
        body: jsonEncode({'email': email, 'password': password}),
      );

      print('Status Code: ${response.statusCode}');
      print('Response Body: ${response.body}');

      if (response.statusCode == 200) {
        final responseBody = jsonDecode(response.body);
        final String token = responseBody['token'];
        await storage.write(key: 'jwtToken', value: token);
        return true;
      } else {
        return false;
      }
    } catch (e) {
      print('Login error: $e');
      return false;
    }
  }

  static Future<void> logout() async {
    await storage.delete(key: 'jwtToken');
  }

  static Future<String?> getToken() async {
    return await storage.read(key: 'jwtToken');
  }
}
