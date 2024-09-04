class Store {
  final int id;
  final String name;
  final String imageUrl;
  final String logoUrl;
  final String description;
  final String distance;
  final double rating;
  final String startingPrice;
  final String address;
  final List<String> menuItems; // List of menu items
  final String timeToPrepare; // Preparation time

  Store({
    required this.id,
    required this.name,
    required this.imageUrl,
    required this.logoUrl,
    required this.description,
    required this.distance,
    required this.rating,
    required this.startingPrice,
    required this.address,
    required this.menuItems,
    required this.timeToPrepare,
  });

  factory Store.fromJson(Map<String, dynamic> json) {
    return Store(
      id: json['id'] ?? 0,
      name: json['name'] ?? '',
      imageUrl:
          json['imageUrl'] ?? 'https://localhost:7299/images/default_image.png',
      logoUrl:
          json['logoUrl'] ?? 'https://localhost:7299/images/default_logo.png',
      description: json['description'] ?? 'No description available',
      distance: json['distance'] ?? 'Unknown distance',
      rating: (json['rating'] ?? 0.0).toDouble(),
      startingPrice: json['startingPrice'] ?? 'Unknown price',
      address: json['address'] ?? 'Unknown address',
      menuItems: List<String>.from(json['menuItems'] ?? []),
      timeToPrepare: json['timeToPrepare'] ?? 'Unknown time',
    );
  }
}
