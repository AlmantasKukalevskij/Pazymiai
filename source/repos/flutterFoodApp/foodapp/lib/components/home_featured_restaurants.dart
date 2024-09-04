import 'package:flutter/material.dart';
import 'package:foodapp/components/store_model.dart';
import 'package:foodapp/components/store_service.dart';
import 'package:foodapp/services/authentication_Service.dart';
import 'package:foodapp/home_page.dart'; // Ensure you have this import for the HomePage

class FeaturedRestaurants extends StatefulWidget {
  @override
  _FeaturedRestaurantsState createState() => _FeaturedRestaurantsState();
}

class _FeaturedRestaurantsState extends State<FeaturedRestaurants> {
  Future<List<Store>>? futureStores;

  @override
  void initState() {
    super.initState();
    loadStores();
  }

  void loadStores() async {
    String? token = await AuthenticationService.getToken();
    if (token != null) {
      futureStores = StoreService.fetchStores(token);
      setState(() {});
    } else {
      print('No token found');
    }
  }

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Column(
        children: [
          FutureBuilder<List<Store>>(
            future: futureStores,
            builder: (context, snapshot) {
              if (snapshot.connectionState == ConnectionState.waiting) {
                return Center(child: CircularProgressIndicator());
              } else if (snapshot.hasError) {
                return Center(child: Text('Error: ${snapshot.error}'));
              } else if (snapshot.hasData && snapshot.data!.isNotEmpty) {
                return ListView.builder(
                  shrinkWrap: true,
                  physics: NeverScrollableScrollPhysics(),
                  itemCount: snapshot.data!.length,
                  itemBuilder: (context, index) {
                    final store = snapshot.data![index];
                    return GestureDetector(
                      onTap: () {
                        // Navigate to HomePage when the card is tapped
                        Navigator.of(context).push(
                          MaterialPageRoute(
                              builder: (context) =>
                                  HomePage()), // Ensure HomePage is the correct destination
                        );
                      },
                      child: Card(
                        margin: const EdgeInsets.symmetric(
                            horizontal: 16.0, vertical: 8.0),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(15.0),
                        ),
                        clipBehavior: Clip.antiAlias,
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Stack(
                              alignment: Alignment.bottomLeft,
                              children: [
                                Image.network(
                                  store.imageUrl,
                                  width: double.infinity,
                                  height: 200,
                                  fit: BoxFit.cover,
                                  errorBuilder: (context, error, stackTrace) {
                                    return Image.asset(
                                      'lib/images/default_image.png',
                                      width: double.infinity,
                                      height: 200,
                                      fit: BoxFit.cover,
                                    );
                                  },
                                ),
                                Positioned(
                                  left: 16,
                                  bottom: 16,
                                  child: CircleAvatar(
                                    backgroundImage:
                                        NetworkImage(store.logoUrl),
                                    radius: 35,
                                    onBackgroundImageError: (_, __) {},
                                  ),
                                ),
                              ],
                            ),
                            Padding(
                              padding: const EdgeInsets.all(16.0),
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text(
                                    store.name,
                                    style:
                                        Theme.of(context).textTheme.headline6,
                                  ),
                                  SizedBox(height: 8),
                                  Text(
                                    store.description,
                                    style:
                                        Theme.of(context).textTheme.subtitle1,
                                  ),
                                  SizedBox(height: 8),
                                  Row(
                                    mainAxisAlignment:
                                        MainAxisAlignment.spaceBetween,
                                    children: [
                                      Text(
                                        store.startingPrice,
                                        style: Theme.of(context)
                                            .textTheme
                                            .subtitle1,
                                      ),
                                      Row(
                                        children: [
                                          Icon(Icons.location_on, size: 17),
                                          Text(
                                            store.distance,
                                            style: Theme.of(context)
                                                .textTheme
                                                .subtitle1,
                                          ),
                                        ],
                                      ),
                                      Row(
                                        children: [
                                          Text(
                                            '⭐️${store.rating}',
                                            style: TextStyle(
                                              fontSize: 17,
                                              fontWeight: FontWeight.bold,
                                              color: Theme.of(context)
                                                  .colorScheme
                                                  .primary,
                                            ),
                                          ),
                                        ],
                                      ),
                                    ],
                                  ),
                                  SizedBox(height: 10),
                                ],
                              ),
                            ),
                          ],
                        ),
                      ),
                    );
                  },
                );
              } else {
                return Center(child: Text('No data'));
              }
            },
          ),
        ],
      ),
    );
  }
}
