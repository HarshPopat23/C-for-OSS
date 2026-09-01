.PHONY: verify clean

verify:
	bash scripts/verify_examples.sh

clean:
	find build -type f -delete 2>/dev/null || true
	rmdir build 2>/dev/null || true

