import 'package:flutter/material.dart';

class MyDescriptionBox extends StatelessWidget {
  const MyDescriptionBox({super.key});

  @override
  Widget build(BuildContext context) {
    //teksto stilius
    var myPrimaryTextStyle =
        TextStyle(color: Theme.of(context).colorScheme.inversePrimary);
    var mySecondaryTextStyle =
        TextStyle(color: Theme.of(context).colorScheme.primary);

    //apsibreziam konteinerio dydi laikui ir kilometram
    const double textContainerWidth = 100;

    return Container(
        decoration: BoxDecoration(
          border: Border.all(color: Theme.of(context).colorScheme.secondary),
          borderRadius: BorderRadius.circular(8),
          color: Theme.of(context).colorScheme.secondary,
        ),
        padding: EdgeInsets.all(25),
        margin: const EdgeInsets.only(left: 25, right: 25, bottom: 25),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            //atstumas iki restorano
            Column(
              mainAxisSize: MainAxisSize.min, // Use the minimum space necessary
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Container(
                  width: textContainerWidth,
                  child: Text(
                    '3.5 km',
                    style: myPrimaryTextStyle,
                    textAlign: TextAlign.center,
                  ),
                ),
                Text(
                  'Atstumas iki restorano',
                  style: mySecondaryTextStyle,
                  textAlign: TextAlign.center,
                ),
              ],
            ),
            //per kiek laiko galite atsiimti
            Column(
              mainAxisSize: MainAxisSize.min, // Use the minimum space necessary
              mainAxisAlignment:
                  MainAxisAlignment.center, // Center the children vertically
              children: [
                Container(
                  width: textContainerWidth, // Fix the container width
                  child: Text(
                    '5-10 min',
                    style: myPrimaryTextStyle,
                    textAlign: TextAlign.center, // Center the text horizontally
                  ),
                ),
                Text(
                  'Laikas užsakymo paruošimui',
                  style: mySecondaryTextStyle,
                  textAlign: TextAlign.center,
                ),
              ],
            ),
          ],
        ));
  }
}
