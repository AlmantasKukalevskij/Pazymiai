import 'package:flutter/material.dart';
import 'package:foodapp/components/drawer.dart'; // Your custom drawer widget
import 'package:foodapp/home_page.dart'; // Path to where HomePage is located
import 'package:foodapp/components/home_shops_nearby.dart'; // Path to where ShopsNearby is located
import 'package:foodapp/components/home_featured_restaurants.dart';
import 'package:foodapp/cart_page.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          'NomNom',
          style: TextStyle(
            color: Theme.of(context).colorScheme.onPrimary,
          ),
        ),
        leading: Builder(
          builder: (BuildContext context) {
            return IconButton(
              icon: const Icon(Icons.menu),
              onPressed: () => Scaffold.of(context).openDrawer(),
              tooltip: MaterialLocalizations.of(context).openAppDrawerTooltip,
            );
          },
        ),
        actions: <Widget>[
          IconButton(
            icon: const Icon(Icons.shopping_cart),
            tooltip: 'Open cart',
            onPressed: () {
              Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => CartPage()),
              );
            },
          ),
        ],
        backgroundColor: Theme.of(context).colorScheme.primary,
      ),
      drawer: const MyDrawer(),
      body: SingleChildScrollView(
        child: Column(
          children: [
            ShopsNearby(), // Add your shops near you widget here
            FeaturedRestaurants(),
            ElevatedButton(
              onPressed: () {
                // Navigate to the HomePage when the button is pressed
                Navigator.of(context).push(
                  MaterialPageRoute(builder: (context) => HomePage()),
                );
              },
              child: const Text('Go to Shop Home'),
            ),
            // ... other widgets you might want to add
          ],
        ),
      ),
      backgroundColor: Theme.of(context).colorScheme.background,
    );
  }
}
