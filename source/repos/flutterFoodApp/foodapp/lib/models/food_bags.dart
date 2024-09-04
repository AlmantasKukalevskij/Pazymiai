import 'package:flutter/material.dart';

//food item
class FoodBag {
  final String name;
  final String description;
  final String imagePath;
  final double price;
  final FoodBagCategory category;
  List<Addon> availableAddons;

  FoodBag({
    required this.name,
    required this.description,
    required this.imagePath,
    required this.price,
    required this.category,
    required this.availableAddons,
  });
}

//bag rarity (legendary, epic, rare)
enum FoodBagCategory {
  legendary,
  epic,
  rare,
}

class Addon {
  String name;

  Addon({required this.name});
}
