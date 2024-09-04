import 'package:flutter/material.dart';
import 'package:foodapp/themes/dark_mode.dart';
import 'package:foodapp/themes/white_mode.dart';

class ThemeProvider with ChangeNotifier {
  ThemeData _themeData = whiteMode;

  ThemeData get themeData => _themeData;

  bool get isDarkMode => _themeData == darkMode;

  set themeData(ThemeData themeData) {
    _themeData = themeData;
    notifyListeners();
  }

  void toggleTheme() {
    if (_themeData == whiteMode) {
      themeData = darkMode;
    } else {
      themeData = whiteMode;
    }
  }
}
