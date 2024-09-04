import 'dart:convert';
import 'package:http/http.dart' as http;
import 'store_model.dart';

class StoreService {
  static Future<List<Store>> fetchStores(String token) async {
    final response = await http.get(
      Uri.parse('https://localhost:7299/Store'),
      headers: {
        'Authorization': 'Bearer $token',
      },
    );

    if (response.statusCode == 200) {
      print('API Response: ${response.body}');
      List<dynamic> storesJson = jsonDecode(response.body);
      return storesJson.map((json) => Store.fromJson(json)).toList();
    } else {
      print('Failed to load stores with status code: ${response.statusCode}');
      throw Exception('Failed to load stores');
    }
  }
}
