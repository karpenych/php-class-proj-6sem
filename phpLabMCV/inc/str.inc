<header>
    <?php
        print_site_head();
    ?>
</header>

<nav>
    <?php
        load_menu();
    ?>
</nav>

<article>
    <?php
        print_page_head($head);
        load_page();
    ?>
</article>

<footer>
    <?php
        print_copyright();
    ?>
</footer>
