import 'dart:js';

import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:foodapp/auth/login_or_register.dart';
import 'package:foodapp/models/restaurant.dart';
import 'package:foodapp/themes/theme_provider.dart';
import 'package:provider/provider.dart';
import 'login.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();

  runApp(
    MultiProvider(
      providers: [
        //theme provideris
        ChangeNotifierProvider(create: (context) => ThemeProvider()),

        //restorano provideris
        ChangeNotifierProvider(create: (context) => Restaurant()),
      ],
      child: const MyApp(),
    ),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: const LoginOrRegister(),
      theme: Provider.of<ThemeProvider>(context).themeData,
    );
  }
}
