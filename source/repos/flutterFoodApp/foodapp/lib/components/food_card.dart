import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:foodapp/models/food_bags.dart';

class FoodBagCard extends StatelessWidget {
  final FoodBag foodBag;
  final void Function()? onTap;

  const FoodBagCard({
    super.key,
    required this.foodBag,
    required this.onTap,
  });

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        GestureDetector(
          onTap: onTap,
          child: Padding(
            padding: const EdgeInsets.all(15),
            child: Row(
              children: [
                //text foodBag details
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(foodBag.name),
                      Text(
                        '\€' + foodBag.price.toString(),
                        style: TextStyle(
                          color: Theme.of(context).colorScheme.primary,
                        ),
                      ),
                      const SizedBox(height: 10),
                      Text(
                        foodBag.description,
                        style: TextStyle(
                          color: Theme.of(context).colorScheme.inversePrimary,
                        ),
                      ),
                    ],
                  ),
                ),

                const SizedBox(
                  width: 15,
                ),
                //foodBag image
                ClipRRect(
                  borderRadius: BorderRadius.circular(7),
                  child: Image.asset(
                    foodBag.imagePath,
                    height: 120,
                  ),
                ),
              ],
            ),
          ),
        ),
        //divider
        Divider(
          color: Theme.of(context).colorScheme.tertiary,
          endIndent: 25,
          indent: 25,
        )
      ],
    );
  }
}
