function filterLinks() {
    const links = document.querySelectorAll('a');
    links.forEach(link => {
        if (link.href.startsWith("https://www.scs.ubbcluj.ro")) {
            link.remove();
        }
    });
}
