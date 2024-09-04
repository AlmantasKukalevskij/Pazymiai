import 'package:flutter/material.dart';
import 'package:foodapp/components/button.dart';
import 'package:foodapp/models/food_bags.dart';
import 'package:foodapp/models/restaurant.dart';
import 'package:provider/provider.dart';

class FoodPage extends StatefulWidget {
  final FoodBag foodBag;

  const FoodPage({
    super.key,
    required this.foodBag,
  });

  @override
  State<FoodPage> createState() => _FoodPageState();
}

class _FoodPageState extends State<FoodPage> {
  //method to add to cart
  void addToCart(FoodBag foodBag) {
    Navigator.pop(context);

    context.read<Restaurant>().addToCart(foodBag);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: SingleChildScrollView(
        // Wrap content with SingleChildScrollView
        child: Column(
          children: [
            Image.asset(widget.foodBag.imagePath),
            Padding(
              padding: const EdgeInsets.all(20.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(
                    widget.foodBag.name,
                    style: TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize: 20,
                    ),
                  ),
                  Text(
                    widget.foodBag.description,
                    style: TextStyle(
                        fontSize: 16,
                        color: Theme.of(context).colorScheme.primary),
                  ),
                  const SizedBox(height: 10),
                  Divider(color: Theme.of(context).colorScheme.secondary),
                  const SizedBox(height: 10),
                  Text(
                    "Informacija",
                    style: TextStyle(
                      color: Theme.of(context).colorScheme.inversePrimary,
                      fontSize: 16,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  const SizedBox(height: 10),
                  Container(
                    decoration: BoxDecoration(
                      border: Border.all(
                          color: Theme.of(context).colorScheme.secondary),
                    ),
                    child: ListView.builder(
                      shrinkWrap: true,
                      physics:
                          ClampingScrollPhysics(), // Allow this ListView to scroll
                      padding: EdgeInsets.zero,
                      itemCount: widget.foodBag.availableAddons.length,
                      itemBuilder: (context, index) {
                        Addon addon = widget.foodBag.availableAddons[index];

                        return CheckboxListTile(
                          title: Text(addon.name),
                          value: false,
                          onChanged: (value) {},
                        );
                      },
                    ),
                  )
                ],
              ),
            ),
            MyButton(
              onTap: () => addToCart(widget.foodBag),
              text: "Pridėti prie krepšelio",
            ),
            const SizedBox(
              height: 25,
            ),
          ],
        ),
      ),
    );
  }
}
