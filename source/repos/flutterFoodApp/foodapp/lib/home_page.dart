import 'package:flutter/material.dart';
import 'package:foodapp/components/current_location.dart';
import 'package:foodapp/components/description_box.dart';
import 'package:foodapp/components/drawer.dart';
import 'package:foodapp/components/food_card.dart';
import 'package:foodapp/components/sliver_app_bar.dart';
import 'package:foodapp/components/tab_bar.dart';
import 'package:foodapp/components/store_model.dart'; // Make sure this import is correct
import 'package:foodapp/food_page.dart';
import 'package:foodapp/models/food_bags.dart';
import 'package:foodapp/models/restaurant.dart';
import 'package:provider/provider.dart';
import 'package:foodapp/food_page.dart';

class HomePage extends StatefulWidget {
  final Store? store; // Pass the store object to this page

  const HomePage({Key? key, this.store}) : super(key: key);

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage>
    with SingleTickerProviderStateMixin {
  late TabController _tabController;

  @override
  void initState() {
    super.initState();
    _tabController =
        TabController(length: FoodBagCategory.values.length, vsync: this);
  }

  @override
  void dispose() {
    _tabController.dispose();
    super.dispose();
  }

  List<Widget> getFoodInThisCategory(List<FoodBag> fullMenu) {
    return FoodBagCategory.values.map((category) {
      List<FoodBag> categoryMenu =
          fullMenu.where((foodbag) => foodbag.category == category).toList();
      return ListView.builder(
        itemCount: categoryMenu.length,
        physics: const NeverScrollableScrollPhysics(),
        padding: EdgeInsets.zero,
        itemBuilder: (context, index) {
          final foodbag = categoryMenu[index];
          return FoodBagCard(
            foodBag: foodbag,
            onTap: () => Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => FoodPage(foodBag: foodbag),
              ),
            ), // Add any specific onTap functionality if required
          );
        },
      );
    }).toList();
  }

  @override
  Widget build(BuildContext context) {
    final Restaurant restaurant = Provider.of<Restaurant>(
        context); // Assuming you provide Restaurant up the tree

    return Scaffold(
      drawer: MyDrawer(),
      body: NestedScrollView(
        headerSliverBuilder: (context, innerBoxIsScrolled) => [
          MySliverAppBar(
            title: MyTabBar(tabController: _tabController),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.end,
              children: [
                Divider(
                  indent: 25,
                  endIndent: 25,
                  color: Theme.of(context).colorScheme.secondary,
                ),
                const MyCurrentLocation(),
                const MyDescriptionBox(),
              ],
            ),
          ),
        ],
        body: TabBarView(
          controller: _tabController,
          children: getFoodInThisCategory(restaurant.menu),
        ),
      ),
    );
  }
}
