import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';

class ShopsNearby extends StatelessWidget {
  static const List<Map<String, String>> shopsNearby = [
    {
      'imageUrl': 'lib/images/EpicFoodBag.png',
      'title': 'Shop 1',
      'subtitle': '5 mins away',
    },
    {
      'imageUrl': 'lib/images/RareFoodBag.png',
      'title': 'Shop 2',
      'subtitle': '7 mins away',
    },
    {
      'imageUrl': 'lib/images/LegendaryFoodBag.png',
      'title': 'Shop 3',
      'subtitle': '8 mins away',
    },
    {
      'imageUrl': 'lib/images/LegendaryFoodBag.png',
      'title': 'Shop 4',
      'subtitle': '10 mins away',
    },
    {
      'imageUrl': 'lib/images/RareFoodBag.png',
      'title': 'Shop 5',
      'subtitle': '12 mins away',
    },
    {
      'imageUrl': 'lib/images/EpicFoodBag.png',
      'title': 'Shop 6',
      'subtitle': '14 mins away',
    },
    {
      'imageUrl': 'lib/images/RareFoodBag.png',
      'title': 'Shop 7',
      'subtitle': '15 mins away',
    },
  ];

  const ShopsNearby({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final colorScheme = Theme.of(context).colorScheme;
    final textTheme = Theme.of(context).textTheme;

    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: Text(
            'Shops near you',
            style: TextStyle(
              fontWeight: FontWeight.bold,
              fontSize: 24,
              color: colorScheme.onSurface,
            ),
          ),
        ),
        SingleChildScrollView(
          scrollDirection: Axis.horizontal,
          child: Row(
            children: shopsNearby.map(
              (shop) {
                return Container(
                  margin: const EdgeInsets.only(right: 12.0),
                  child: GestureDetector(
                    onTap: () {
                      // On click redirect
                    },
                    child: Column(
                      children: [
                        CircleAvatar(
                          radius: 37,
                          backgroundColor: colorScheme.primary,
                          child: CircleAvatar(
                            radius: 36,
                            backgroundColor: colorScheme.background,
                            child: ClipOval(
                              child: Image.asset(shop['imageUrl']!),
                            ),
                          ),
                        ),
                        const SizedBox(height: 8.0),
                        Text(
                          shop['title']!,
                          maxLines: 1,
                          overflow: TextOverflow.ellipsis,
                          style: textTheme.bodySmall!
                              .copyWith(fontWeight: FontWeight.bold),
                        ),
                        Text(
                          shop['subtitle']!,
                          maxLines: 1,
                          overflow: TextOverflow.ellipsis,
                          style: textTheme.bodySmall,
                        ),
                      ],
                    ),
                  ),
                );
              },
            ).toList(),
          ),
        ),
        const SizedBox(height: 16.0),
        Divider(
          color: Theme.of(context).colorScheme.primary,
          indent: 8.0,
          endIndent: 8.0,
        ),
      ],
    );
  }
}
