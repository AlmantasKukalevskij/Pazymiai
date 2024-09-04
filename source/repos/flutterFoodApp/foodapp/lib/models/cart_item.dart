import 'package:foodapp/models/food_bags.dart';

class CartItem {
  FoodBag foodBag;
  int quantity;

  CartItem({
    required this.foodBag,
    this.quantity = 1,
  });

  double get totalPrice {
    return (foodBag.price) * quantity;
  }
}
