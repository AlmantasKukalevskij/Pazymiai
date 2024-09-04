import 'package:collection/collection.dart';
import 'package:flutter/material.dart';
import 'package:foodapp/models/cart_item.dart';
import 'package:foodapp/models/food_bags.dart';
import 'package:intl/intl.dart';

class Restaurant extends ChangeNotifier {
  //masto listas
  final List<FoodBag> _menu = [
    //rare foodBag
    FoodBag(
      name: "Retas paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/RareFoodBag.png',
      price: 3.99,
      category: FoodBagCategory.rare,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 2-3 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    FoodBag(
      name: "Retas paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/RareFoodBag.png',
      price: 3.99,
      category: FoodBagCategory.rare,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 2-3 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    FoodBag(
      name: "Retas paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/RareFoodBag.png',
      price: 3.99,
      category: FoodBagCategory.rare,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 2-3 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    //Epic foodBag
    FoodBag(
      name: "Unikalus paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/EpicFoodBag.png',
      price: 5.99,
      category: FoodBagCategory.epic,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 3-5 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    FoodBag(
      name: "Unikalus paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/EpicFoodBag.png',
      price: 5.99,
      category: FoodBagCategory.epic,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 3-5 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    FoodBag(
      name: "Unikalus paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/EpicFoodBag.png',
      price: 5.99,
      category: FoodBagCategory.epic,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 3-5 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),

    //Legendary foodBag

    FoodBag(
      name: "Legendinis paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/LegendaryFoodBag.png',
      price: 7.99,
      category: FoodBagCategory.legendary,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 5-7 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    FoodBag(
      name: "Legendinis paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/LegendaryFoodBag.png',
      price: 7.99,
      category: FoodBagCategory.legendary,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 5-7 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
    FoodBag(
      name: "Legendinis paslapčių maišelis",
      description:
          "Šiame maišelyje galite tikėtis įvairių maisto prekių kurios atitiks kainą",
      imagePath: 'lib/images/LegendaryFoodBag.png',
      price: 7.99,
      category: FoodBagCategory.legendary,
      availableAddons: [
        Addon(name: "Galite tikėtis gauti maždaug 5-7 prekes."),
        Addon(name: "Prekių gražinti negalima."),
        Addon(name: "Prekes atsiimkite iš kavines/restorano darbuotojo"),
      ],
    ),
  ];
  //get menue
  List<FoodBag> get menu => _menu;
  List<CartItem> get cart => _cart;

  //user cart
  final List<CartItem> _cart = [];

  //OPERACIJOS
  //prideti i pirkiniu krepseli
  void addToCart(FoodBag foodBag) {
    //patikrinam ar jau yra tokia preke, tuomet galime tiesiog padidinti quantity
    CartItem? cartItem = _cart.firstWhereOrNull((item) {
      //chek if food item is the same
      bool isSameFood = item.foodBag == foodBag;

      return isSameFood;
    });
    //jeigu preke jau krepselyje, padidinam jos kieki
    if (cartItem != null) {
      cartItem.quantity++;
    }
    //jei ne, pridedame preke
    else {
      _cart.add(
        CartItem(
          foodBag: foodBag,
        ),
      );
    }
    notifyListeners();
  }

  //isimti preke is krepselio
  void removeFromCart(CartItem cartItem) {
    int cartIndex = _cart.indexOf(cartItem);

    if (cartIndex != -1) {
      if (_cart[cartIndex].quantity > 1) {
        _cart[cartIndex].quantity--;
      } else {
        _cart.removeAt(cartIndex);
      }
    }
    notifyListeners();
  }

  //gauti bendra krepselio kaina
  double getTotalPrice() {
    double total = 0.0;

    for (CartItem cartItem in _cart) {
      double itemTotal = cartItem.foodBag.price;

      total += itemTotal * cartItem.quantity;
    }
    return total;
  }

  //gauti bendra krepselio prekiu skaiciu
  int getTotalItemCount() {
    int totalItemCount = 0;

    for (CartItem cartItem in _cart) {
      totalItemCount += cartItem.quantity;
    }
    return totalItemCount;
  }

  //istrinti visa krepseli
  void clearCart() {
    _cart.clear();
    notifyListeners();
  }

  //PAPILDOMAI
  //sugeneruoti ceki
  String displayCartReceipt() {
    final receipt = StringBuffer();
    receipt.writeln("Jūsų čekis.");
    receipt.writeln();

    String formattedDate =
        DateFormat('yyyy-MM-dd HH:mm:ss').format(DateTime.now());

    receipt.writeln(formattedDate);
    receipt.writeln();
    receipt.writeln("==========");

    for (final CartItem in _cart) {
      receipt.writeln(
          "${CartItem.quantity} x ${CartItem.foodBag.name} - ${_formatPrice(CartItem.foodBag.price)}");
    }
    receipt.writeln("==========");
    receipt.writeln();
    receipt.writeln("Visos prekės: ${getTotalItemCount()}");
    receipt.writeln("Bendra suma: ${_formatPrice(getTotalPrice())}");

    return receipt.toString();
  }

  String _formatPrice(double price) {
    return "\$${price.toStringAsFixed(2)}";
  }
}
