import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:foodapp/components/button.dart';
import 'package:foodapp/components/textfield.dart';
import 'package:foodapp/services/authentication_Service.dart';
import 'package:foodapp/main_home_screen.dart';

class LoginPage extends StatefulWidget {
  final void Function()? onTap;

  const LoginPage({super.key, required this.onTap});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  // text editing controllers
  final TextEditingController emailController = TextEditingController();
  final TextEditingController passwordController = TextEditingController();

  // login method
  void login() async {
    final email = emailController.text.trim();
    final password = passwordController.text.trim();

    final bool isLoggedIn = await AuthenticationService.login(email, password);

    if (isLoggedIn) {
      Navigator.push(
        context,
        MaterialPageRoute(builder: (context) => const HomeScreen()),
      );
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Invalid login credentials')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).colorScheme.background,
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            //logotipo tekstas
            Icon(
              Icons.lock_open_rounded,
              size: 72,
              color: Theme.of(context).colorScheme.inversePrimary,
            ),

            const SizedBox(height: 25),

            Text(
              "NomNom",
              style: TextStyle(
                fontSize: 16,
                color: Theme.of(context).colorScheme.inversePrimary,
              ),
            ),

            const SizedBox(height: 25),

            //email text
            MyTextField(
              controller: emailController,
              hintText: "El. Paštas",
              obscureText: false,
            ),
            const SizedBox(height: 10),

            //password text
            MyTextField(
              controller: passwordController,
              hintText: "Slaptąžodis",
              obscureText: true,
            ),
            const SizedBox(height: 25),
            //login button
            MyButton(
              text: "LogIn",
              onTap: () async {
                bool success = await AuthenticationService.login(
                    emailController.text.trim(),
                    passwordController.text.trim());
                if (success) {
                  Navigator.pushReplacement(
                      context,
                      MaterialPageRoute(
                          builder: (context) => const HomeScreen()));
                } else {
                  ScaffoldMessenger.of(context).showSnackBar(SnackBar(
                      content: Text('Login failed, please try again')));
                }
              },
            ),
            const SizedBox(height: 15),
            //register option
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                GestureDetector(
                  onTap: widget.onTap,
                  child: Text(
                    "Registruokis dabar!",
                    style: TextStyle(
                      color: Theme.of(context).colorScheme.inversePrimary,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
