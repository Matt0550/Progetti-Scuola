function openMenu() {
    var menu = document.getElementById("menu");

    if (menu.classList.contains("hidden")) {
        menu.classList.remove("hidden");
    } else {
        menu.classList.add("hidden");
    }
}