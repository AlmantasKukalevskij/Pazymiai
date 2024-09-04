import 'package:flutter/material.dart';
import 'package:foodapp/components/store_model.dart'; // Import the correct path to Store model

class RestaurantMenuPage extends StatelessWidget {
  final Store store;

  RestaurantMenuPage({Key? key, required this.store}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(store.name), // Display the store name
      ),
      body: SingleChildScrollView(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            // Display the store details
            Text("Address: ${store.address}"), // Display the address
            Text(
                "Description: ${store.description}"), // Description of the store
            Text("Distance: ${store.distance}"), // Distance of the store
            Text("Starting Price: ${store.startingPrice}"), // Starting price
          ],
        ),
      ),
    );
  }
}
