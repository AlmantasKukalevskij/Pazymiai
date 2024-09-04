import 'package:flutter/material.dart';
import 'package:foodapp/auth/login_or_register.dart';
import 'package:foodapp/components/drawer_title.dart';
import 'package:foodapp/main_home_screen.dart';
import 'package:foodapp/settings.dart';
import 'package:foodapp/login.dart'; // Import login page to navigate to it

class MyDrawer extends StatelessWidget {
  const MyDrawer({super.key});

  @override
  Widget build(BuildContext context) {
    return Drawer(
      backgroundColor: Theme.of(context).colorScheme.background,
      child: Column(
        children: [
          //app logotip
          Padding(
            padding: const EdgeInsets.only(top: 100.0),
            child: Icon(
              Icons.lock_open_rounded,
              size: 60,
              color: Theme.of(context).colorScheme.inversePrimary,
            ),
          ),
          //home list title
          MyDrawerTitle(
            text: "N A M A I",
            icon: Icons.home,
            onTap: () {
              Navigator.pop(context);
              Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => const HomeScreen()),
              );
            },
          ),
          //settings list title
          MyDrawerTitle(
            text: "N U S T A T Y M A I",
            icon: Icons.settings,
            onTap: () {
              Navigator.pop(context);
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (context) => const SettingsPage(),
                ),
              );
            },
          ),
          //logout list title

          const Spacer(),

          MyDrawerTitle(
            text: "A T S I J U N G T I",
            icon: Icons.logout,
            onTap: () {
              Navigator.pop(context); // Close the drawer
              Navigator.pushReplacement(
                // Replace the current route with the login page
                context,
                MaterialPageRoute(builder: (context) => LoginOrRegister()),
              );
            },
          ),
          const SizedBox(height: 25),
        ],
      ),
    );
  }
}
